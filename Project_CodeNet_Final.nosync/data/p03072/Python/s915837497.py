#山の数
n = int(input())
#各山の高さ
h = list(map(int, input().split()))
cou = 1
for i in range(1, n):
    if not max(h[:i+1]) == h[i]:
        continue

    if not h[i-1] <= h[i]:
        continue

    cou+=1

print (cou)
