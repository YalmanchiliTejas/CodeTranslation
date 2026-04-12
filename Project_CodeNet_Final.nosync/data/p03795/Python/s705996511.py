def discount(x):
  return (x // 15) * 200

def cost(x):
  return x * 800

N = int(input())
Sum = cost(N) - discount(N)

print(Sum)