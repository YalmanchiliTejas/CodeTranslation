import sys
input = sys.stdin.readline

n, x, m = map(int,input().split())

A = [0] * m
for i in range(m):
    A[i] = (i*i)%m

V = [-1] * m
B = [x]
xx = x

cnt = 0
while V[xx] == -1:
    V[xx] = cnt
    cnt += 1
    xx = A[xx]
    B.append(xx)

end = V[xx]
# print(end)

# print(B[:10])
# print(len(B))
# print()
S = [B[0]]
for i in range(1, len(B)):
    S.append(B[i] + S[-1])

# print(S[:10])
# print(sum(S) * (n//len(B)) + sum(S[:n%len(B)]))

if end >= n:
    print(sum(B[:n]))
else:
    n -= end+1
    # print("newn",n)
    ans = sum(B[:end+1])
    # print("ans",ans)
    ans += sum(B[end+1:]) * (n // (len(S)-end-1))
    # print("ans",ans)
    ans += sum(B[end+1:end+1+n % (len(S)-end-1)])
    print(ans)