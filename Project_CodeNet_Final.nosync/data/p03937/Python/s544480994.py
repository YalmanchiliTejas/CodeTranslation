import sys

def solve():
    input = sys.stdin.readline
    H, W = map(int, input().split())
    A = [input().strip("\n") for _ in range(H)]
    count = 0
    for h in range(H):
        for w in range(W):
            if A[h][w] == "#": count += 1
    if count + 1 == H + W: print("Possible")
    else: print("Impossible")


    return 0

if __name__ == "__main__":
    solve()