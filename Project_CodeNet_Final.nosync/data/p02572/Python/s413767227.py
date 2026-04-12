n = input()
li = list(map(int, input().split()))

sum_ = sum(li)
result = 0

for i in range(len(li)):
  sum_ -= li[i]
  result += sum_ * li[i]
  
print(result % (10 ** 9 + 7))