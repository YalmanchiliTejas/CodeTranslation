#!/user/bin/env python
#pythonプログラムであることを示している

# -*- coding: utf-8 -*-
"""
このプログラムはPythonを書く際のテンプレとなっています。これをコピペしてコーディングを行なってください。
なお字下げしないこと！！
"""

__author_ = 'Maruta Yuzuha'
__version_ = '1.0.0'
__date__ = '2019/12/25'

def main():
    """
    ここでプログラムの解説を行う
     >>main()
    Hello world.
    0
    """
    s = input().split()
    if (s[0] == s[1]) and int(s[0]) <= 100 and int(s[0]) >= 0:
        print('Yes')
    else: 
        print('No')
    
    return 0

if __name__ == '__main__':
    #上記のifの記述によってこのスクリプトファイルが起動された時だけ実行する部分になる。
    #ちなみにスクリプトが "モジュールとして"インポートされた時には実行されない、

    #単体テスト:モジュールのdocstring(ドキュメンテーション文字列)に記載された全ての対話実行例が書かれている通りに動作するかを確認
    #python ファイル名 -v
    import doctest
    doctest.testmod()

    #実際にmain()を呼び出して、結果を得て、その結果でPythonシステムを終える
    import sys
    sys.exit(main())