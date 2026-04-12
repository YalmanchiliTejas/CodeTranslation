
def main():
  n = int(input())
  ans = ""
  dics = []
  
  az = "abcdefghijklmnopqrstuvwxyz"

  for i in range(n):
    dic = {}
    s = input()
    for c in az:
      dic[c] = s.count(c)
    dics.append(dic)

  for c in az:
    can_use = True
    m = 50

    for dic in dics:
      if dic[c] == 0:
        can_use = False
        break

      m = min(m, dic[c])

    if(can_use):
      ans += c * m

  print(ans)

if __name__ == "__main__":
    main()