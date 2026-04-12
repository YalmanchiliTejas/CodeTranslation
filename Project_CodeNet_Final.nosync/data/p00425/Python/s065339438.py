def main():
  while True:
    n = int(input())
    if not n:
      break
  
    D = [1, 2, 3, 4, 5, 6]
    ans = 1
  
    for i in range(n):
      s = input()[0]
  
      if s == "N":
        temp = D[0]
        D[0] = D[1]
        D[1] = D[5]
        D[5] = D[4]
        D[4] = temp
  
      elif s == "S":
        temp = D[0]
        D[0] = D[4]
        D[4] = D[5]
        D[5] = D[1]
        D[1] = temp
  
      elif s == "E":
        temp = D[0]
        D[0] = D[3]
        D[3] = D[5]
        D[5] = D[2]
        D[2] = temp
  
      elif s == "W":
        temp = D[0]
        D[0] = D[2]
        D[2] = D[5]
        D[5] = D[3]
        D[3] = temp
  
      elif s == "L":
        temp = D[1]
        D[1] = D[3]
        D[3] = D[4]
        D[4] = D[2]
        D[2] = temp
  
      elif s == "R":
        temp = D[1]
        D[1] = D[2]
        D[2] = D[4]
        D[4] = D[3]
        D[3] = temp
  
      ans += D[0]
  
    print(ans)

main()
