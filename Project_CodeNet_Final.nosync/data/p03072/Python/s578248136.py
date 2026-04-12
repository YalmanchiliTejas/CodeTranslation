N = int(input())
ListH = list(map(int,input().split()))
result = 0
for i in range(N):
    out = False
    for k in range(i):
        if k >= 0:
            if ListH[k] > ListH[i]:
                out = True
    if not out :
        result += 1
print(result)