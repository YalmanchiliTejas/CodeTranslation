n = int(input())
elems = []
pref = []
raw = input().split(" ")
idx = 0
while(idx < n):
    elem = int(raw[idx]);
    elems.append(elem)
    if(idx == 0):
        pref.append(elems[idx])
    else:
        pref.append(pref[idx - 1] + elem)
    idx += 1

sum = 0
for idx in range(n):
    sum += elems[idx] * (pref[n - 1] - pref[idx])

print(sum%1000000007)
