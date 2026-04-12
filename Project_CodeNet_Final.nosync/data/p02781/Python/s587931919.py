N = int(input())
K = int(input())
keta = len(str(N))

def kosu(p):
  if p == 1:
    answer = [9, 0, 0]
  elif p == 2:
    answer = [9, 81, 0]
  elif p == 3:
    answer = [9, 162, 729]
  else:
    k1 = 9
    k2 = (9 ** 2) * (p - 1)
    k3 = int((9 ** 3) * (p - 1) * (p - 2) / 2)
    answer = [k1, k2, k3]
  return answer

if keta == 1:
  if K == 1:
    print(N)
  else:
    print("0")
  quit()
  
ans = 0  
for i in range(1, keta):
  ans += kosu(i)[K - 1]

#print(ans)  
if K == 1:
  ans += int(str(N)[0])
elif K == 2:
  y = 0
  i = 1
  while y == 0:
    if int(str(N)[i]) != 0:
      y = i
      ans += int(str(N)[i]) + 9 * (keta -y - 1)
    i += 1
    if i == keta:
      y = keta
    
  #print(x)
  ans += (int(str(N)[0]) - 1) * 9 * (keta - 1)
  
else:
  if keta >= 3:
    ans += int((int(str(N)[0]) - 1) * (9 ** 2) * (keta - 1) * (keta - 2) / 2)
    #print(ans)
    x = 0
    i = 1
    while x <= 1:
      if int(str(N)[i]) != 0:
        x += 1
        if x == 1:
          ans += (int(str(N)[i]) - 1) * (9 * (keta - i - 1))
          if i <= keta - 3:
            ans += (9 ** 2) * (keta - i - 1) * (keta - i - 2) / 2
        else:# x = 2
          ans += int(str(N)[i]) + 9 * (keta - i - 1)
      i += 1
      if (i == keta - 1) and (x == 0):
        x = 2
      if i == keta:
        x = 2
        

print(int(ans))
    
