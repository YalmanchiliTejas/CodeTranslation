N = int(input())
counter = [51]*26
for i in range(N):
    s = input()
    for j in range(97,123):
        counter[j-97] = min(counter[j-97],s.count(chr(j)))
ps = ''
for i in range(26):
    ps += chr(i+97)*counter[i]
print(ps)