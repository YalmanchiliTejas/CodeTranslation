H,W = map(int,input().split())
A = []
for i in range(H):
    a = list(input())
    if '#' in a:
        A.append(a)
ans = []
for col in zip(*A):
    if '#' in col:
        ans.append(col)
for i in zip(*ans):
    print(''.join(i))