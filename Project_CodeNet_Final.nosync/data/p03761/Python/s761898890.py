N = int(input())
def counter(array):
    from collections import Counter
    return list(Counter(array).most_common())

L = []
C = []
for _ in range(N):
    L.append(list(input()))
s = set(L[0])
for l in L:
    s &= set(l) 
    c = counter(l)
    C.append(c)
if s == set():
    print()
    quit()
L = []
for char in s:
    cnt = 10**10
    for c in C:
        for x in c:
            if x[0] == char:
                cnt = min(cnt,x[1])
    L.append((char,cnt))
L.sort()
ans = ""
for x in L:
    ans += x[0] * x[1]
print(ans)
