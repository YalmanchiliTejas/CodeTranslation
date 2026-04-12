def main():
  n, x ,m = map(int, input().split())
  a = [0, x]
  place = [-1]*m
  place[x] = 1
  num = 2
  while True:
    x = (x**2%m)
    if place[x] >= 0:
      break
    a.append(x)
    place[x] = num
    num += 1
  loop = num-place[x]
  loop_sum = sum(a[place[x]:])
  loop_st = sum(a[:place[x]])
  
  if n <= place[x]:
    print(sum(a[:n+1]))
  else:
    n -= place[x]-1
    print(loop_st + loop_sum*(n//loop) + sum(a[place[x]:n%loop+place[x]]))
  
if __name__ == "__main__":
  main()