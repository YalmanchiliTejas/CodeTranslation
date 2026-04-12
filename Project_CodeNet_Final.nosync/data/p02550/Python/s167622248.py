N, X, M = map(int, input().split())

a = X
count = 1
ai = [a]
mapping = [0 for i in range(10**5+1)]
mapping[a] = count
count += 1
for i in range(1, 10**5+1):
    a = (a ** 2 ) % M
    if mapping[a] == 0:
        ai.append(a)
        mapping[a] = count
    else:
        break
    count += 1
s = mapping[a]
e = mapping[ai[-1]]
loop = e - s + 1
# print(s, e, ai)
if N <= e:
    print(sum(ai[:N]))
else:
    syo = (N - e) // loop
    amari = (N - e) % loop
    loop_total = sum(ai[s-1:e])
    # print(loop_total * syo, sum(ai[s-1:s+amari-1]))
    ans = sum(ai) + loop_total * syo + sum(ai[s-1:s+amari-1])
    print(ans)
# print(s, e, syo, amari, loop_total)