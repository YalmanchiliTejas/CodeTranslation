h,w = map(int, input().split())
ans = []
for i in range(h):
    a = list(input())
    if a[0]=="." and len(set(a)) == 1:
        continue
    ans.append(a)

ans1 = []
for j in list(zip(*ans)):
    if j[0]=="." and len(set(j)) == 1:
        continue
    ans1.append(j)

for k in list(zip(*ans1)):
    print( ''.join(k))