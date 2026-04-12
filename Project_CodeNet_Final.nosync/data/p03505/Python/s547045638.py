import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

K,A,B = map(int,input().split())

if K <= A:
    answer = 1
else:
    if A-B <= 0:
        answer = -1
    else:
        d = A-B
        x = K-A
        x += (-x)%d
        answer = 2 * x//d + 1
print(answer)