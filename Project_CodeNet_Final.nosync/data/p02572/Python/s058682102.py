n = int(input())
an = [int(num)  for num in input().split()]

an_total = sum(an)
answer = 0
for i in range(len(an)-1):
  an_total -= an[i]
  answer +=  an[i] * an_total
print(answer%1000000007)