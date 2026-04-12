import bisect


def main():
  x = [int(input()) for _ in range(int(input()))]
  c = [x[-1]]

  for i in range(len(x) - 2, -1, -1):
    j = bisect.bisect(c, x[i])

    if j == len(c):
      c.append(x[i])
    else:
      c[j] = x[i]

  print(len(c))


if __name__ == '__main__':
  main()
