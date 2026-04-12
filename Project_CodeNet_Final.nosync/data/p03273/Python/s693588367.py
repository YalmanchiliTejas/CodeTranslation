import numpy as np


def main():
    h, w = map(int, input().split())
    board = [list(input()) for _ in range(h)]
    board_arr = np.array(board)

    del_h = np.where(np.all(board_arr == '.', axis=1))
    board_arr = np.delete(board_arr, del_h, axis=0)
    del_w = np.where(np.all(board_arr == '.', axis=0))
    board_arr = np.delete(board_arr, del_w, axis=1)
    for row in board_arr:
        row = row.tolist()
        ans = ''.join(row)
        print(ans)


if __name__ == "__main__":
    main()
