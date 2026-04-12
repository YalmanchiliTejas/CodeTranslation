def bis(h, a):
  l, r = 0, len(h)-1
  while l<r:
    mid = (l+r) // 2
    if h[mid] >= a:
      l = mid + 1
    else:
      r = mid
  return l

def main():
  n = int(input())
  alist = [int(input()) for _ in range(n)]
  ans = 1
  h = [alist[0]]
  for a in alist[1:]:
    if a <= h[-1]:
      h.append(a)
      ans += 1
    else:
      i = bis(h, a)
      h[i] = a
  print(ans)


if __name__ == '__main__':
  main()
