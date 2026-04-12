def ex_euclid(a, b):
  x0, x1 = 1, 0
  y0, y1 = 0, 1
  z0, z1 = a, b
  
  while z1 != 0:
    q = z0 // z1
    z0, z1 = z1, z0 % z1
    x0, x1 = x1, x0 - q * x1
    y0, y1 = y1, y0 - q * y1
  
  return z0, x0, y0
 
def mod_inv(a, n):
  g, x, _ = ex_euclid(a, n)
  if g != 1:
    print("modular inverse does not exist")
  else:
    return x % n

N = int(input())
A = list(map(int, input().split()))
M = 10**9 + 7
normal = 0
squared = 0
ans = 0
for a in A:
  normal = normal + a % M
  squared = squared + a*a % M
ans = (ans + normal * normal) % M
ans = (ans - squared) % M
ans = ans * mod_inv(2, M) % M
print(ans)