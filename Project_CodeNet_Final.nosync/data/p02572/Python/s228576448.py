n = int(input())
a = list(map(int, input().split()))

ans = 0
mod = 10 ** 9 + 7
a_r = list(reversed(a))
sumlist = [a_r[0]]
for i in range(1,len(a)):
  sumlist.append(sumlist[-1] + a_r[i])
sumlist.reverse()
sumlist = sumlist[1:]

for i in range(len(sumlist)):
  ans += a[i] * sumlist[i]

print(ans%mod)
