import sys
input = sys.stdin.readline
def ii(): return int(input())
def mi(): return map(int, input().rstrip().split())
def lmi(): return list(map(int, input().rstrip().split()))
def li(): return list(input().rstrip())
# template #


N = ii()
H = lmi()
cnt = 0
for i in range(N):
    for j in range(i):
        if H[j] > H[i]:
            break
    else:
        cnt += 1

print(cnt)
