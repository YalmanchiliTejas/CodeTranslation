h, w = map(int, input().split())
ans = []

for i in range(h):
    A = list(input())
    if  '#' in A:
        ans.append(A)
        
count = [0] * w
for i in range(len(ans)):
    for j in range(w):
        if ans[i][j] == '.':
            count[j] += 1

num = len(ans)
for i in range(num):
    for j in range(w - 1, -1, -1):
        if count[j] == num:
            del ans[i][j]
        
for i in range(len(ans)):
    print(''.join(ans[i]))