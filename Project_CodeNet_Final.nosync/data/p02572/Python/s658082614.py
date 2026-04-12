N = int(input())

data = input().split()

data = [int(s) for s in data]

num = 0
ans = 0
sum = sum(data)

for i in range(N) :
  num += data[i]
  ans += (sum - num) * data[i]

print(ans % 1000000007)