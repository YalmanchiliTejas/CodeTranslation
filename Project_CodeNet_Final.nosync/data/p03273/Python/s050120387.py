# coding: utf-8


def main():
    h, w = map(int, input().split())
    a = []

    # 「すべて白」以外の行を登録
    for _ in range(h):
        src = str(input())
        if len(src.replace('.', '')) > 0:
            a.append(src)

    # col行目がすべて白でないインデックスを取得
    blackpos = []
    for col in range(w):
        white = 0
        for row in range(len(a)):
            if a[row][col] == '.':
                white += 1
        if white != len(a):
            blackpos.append(col)

    # すべて白でないindexのもののみprint
    for row in range(len(a)):
        for col in blackpos:
            print(a[row][col], end='')
        print()


if __name__ == '__main__':
    main()
