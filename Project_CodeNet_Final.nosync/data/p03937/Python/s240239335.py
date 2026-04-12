#!/usr/bin/env python3

H, W = list(map(int, input().split()))
a_table = []

for _ in range(H):
    a_list = list(input())
    a_table.append(a_list)

if a_table[0][0] != "#" or a_table[H - 1][W - 1] != "#":
    is_ok = False
else:
    # 連結箇所のチェック
    section_list = []
    is_ok = True
    for j in range(H):
        exist_section = False
        end_section = False
        start_idx = None
        end_idx = None
        for i in range(W):
            if a_table[j][i] == "#":
                if end_section:
                    # 連結箇所が複数あるのでアウト
                    is_ok = False
                    break
                elif exist_section:
                    # 連続した'#'
                    continue
                else:
                    # 最初の'#'
                    exist_section = True
                    start_idx = i
            else:
                if exist_section and (not end_section):
                    end_section = True
                    end_idx = i - 1
                    section_list.append((start_idx, end_idx))
                else:
                    # 連結部分終了後の'.' または 連結部分開始前の'.'
                    continue

        if exist_section and (not end_section):
            end_idx = W - 1
            section_list.append((start_idx, end_idx))
        elif not exist_section:
            is_ok = False

        if is_ok:
            if j != 0:
                if section_list[-2][1] != section_list[-1][0]:
                    is_ok = False

        if not is_ok:
            break

ans = "Possible" if is_ok else "Impossible"
print(ans)
