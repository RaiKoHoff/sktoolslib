// sktoolslib - common files for SK tools

// Copyright (C) 2012, 2020 - Stefan Kueng

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//

#pragma once

#include "ResourceFile.h"

class CResourceTextFile : public CResourceFile
{
public:
    CResourceTextFile();
    CResourceTextFile(const CResourceTextFile &);
    virtual ~CResourceTextFile();

    enum ConvertAction
    {
        NoConvertAction = 0,
        ConvertToUnicode,
        ConvertToAnsi
    };

    enum BomAction
    {
        NoBomAction = 0,
        RemoveBom,
        AddBom
    };

    wchar_t *     DuplicateTextBuffer();
    wchar_t *     GetTextBuffer() { return m_pszText; }
    BomAction     GetBomAction() { return m_eBomAction; }
    ConvertAction GetConvertAction() { return m_eConvertAction; }

public:
    void     Close();
    wchar_t *DetachTextBuffer();
    BOOL     Open(HINSTANCE     hInstance,
                  LPCWSTR       lpszResId,
                  LPCWSTR       lpszResType = L"TEXT",
                  ConvertAction eConvert    = NoConvertAction,
                  BomAction     eBomAction  = NoBomAction);
    size_t   ReadLine(wchar_t *buf, size_t nBufLen);
    BOOL     SetTextBuffer(wchar_t *buf, DWORD len,
                           ConvertAction eConvert   = NoConvertAction,
                           BomAction     eBomAction = NoBomAction);

protected:
    wchar_t *     m_pszText;        // text file buffer
    BomAction     m_eBomAction;     // BOM action requested at file open
    ConvertAction m_eConvertAction; // conversion requested at file open
};
