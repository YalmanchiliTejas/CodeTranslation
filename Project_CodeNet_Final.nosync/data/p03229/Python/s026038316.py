from collections import deque

n = int(input())
a = [0 for i in range(n)]
for i in range(n):
    a[i] = int(input())

a.sort()

d = deque()

lft = False
smll = False

d.append(a[0])
fst = 1
end = n-1

for i in range(n-1):
    if not(smll):
        if not(lft):
            d.appendleft(a[end])
            end -= 1
            lft = True
        else:
            d.append(a[end])
            end -= 1
            lft = False
            smll = True
    else:
        if not(lft):
            d.appendleft(a[fst])
            fst += 1
            lft = True
        else:
            d.append(a[fst])
            fst += 1
            lft = False
            smll = False

memo = d.pop()
ans = 0
for i in range(n-1):
    memo2 = d.pop()
    ans += abs(memo-memo2)
    memo = memo2
    


d.append(a[n-1])
fst = 0
end = n-2
lft = False
smll = True


for i in range(n-1):
    if not(smll):
        if not(lft):
            d.appendleft(a[end])
            end -= 1
            lft = True
        else:
            d.append(a[end])
            end -= 1
            lft = False
            smll = True
    else:
        if not(lft):
            d.appendleft(a[fst])
            fst += 1
            lft = True
        else:
            d.append(a[fst])
            fst += 1
            lft = False
            smll = False

memo3 = d.pop()
ans2 = 0
for i in range(n-1):
    memo4 = d.pop()
    ans2 += abs(memo3-memo4)
    memo3 = memo4
    
ans = max(ans,ans2)
    
print(ans)
