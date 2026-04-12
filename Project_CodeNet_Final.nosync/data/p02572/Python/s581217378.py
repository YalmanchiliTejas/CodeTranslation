def square(x):
  y = x**2
  return y


n = int(input())
al = list(map(int, input().split()))
als = list(map(square, al))

print(((sum(al)**2-sum(als))//2)%((10**9)+7))


