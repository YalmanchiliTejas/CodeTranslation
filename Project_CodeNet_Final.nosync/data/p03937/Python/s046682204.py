# -*-coding: utf-8 -*-
def check(A, h, w):
    cnt = 0
    if A[h-1][w] == "#":
        cnt += 1
    if A[h][w-1] == "#":
        cnt += 1
    if A[h][w+1] == "#":
        cnt += 1
    if A[h+1][w] == "#":
        cnt += 1
    return cnt

def main():
    H, W = map(int, input().split())
    A = ["." * (W+2)]
    for i in range(H):
        A.append("." + input() + ".")
    A.append("." * (W + 2))
    #print(A)
    ans = "Possible"
    for w in range(1, W+1):
        for h in range(1, H+1):
            if A[h][w] == "#":
                if w == h == 1:
                    if check(A, h, w) != 1:
                        ans = "Impossible"
                elif h == H and w == W:
                    if check(A, h, w) != 1:
                        ans = "Impossible"
                elif check(A, h, w) == 2:
                    if A[h-1][w] == A[h+1][w] == "#" and A[h][w-1] == A[h][w+1] == ".":     # 直線(縦)
                        pass
                    elif A[h-1][w] == A[h+1][w] == "." and A[h][w-1] == A[h][w+1] == "#":   # 直線(横)
                        pass
                    elif A[h-1][w] == A[h][w+1] == "#" and A[h+1][w] == A[h][w-1] == ".":   # L字
                        pass
                    elif A[h+1][w] == A[h][w-1] == "#" and A[h-1][w] == A[h][w+1] == ".":   # L時
                        pass
                    else:
                        ans = "Impossible"
                else:
                    ans = "Impossible"
    print(ans)
if __name__ == '__main__':
    main()