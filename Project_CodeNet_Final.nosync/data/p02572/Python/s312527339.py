n = int(input())
a = list(map(int,input().split()))
b=sum(a)
score=0
for i in range(len(a)):
  b -= a[i]
  score+=a[i]*b
  
print(score%(10**9+7))