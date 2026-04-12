def main():
  H, W = list(map(int, input().split()))

  count = 0

  for i in range(H):
    row = input()
    for j in range(W):
      if(row[j] == '#'):
        count += 1

  print("Possible" if W + H - 1 == count else "Impossible")

if __name__ == "__main__":
  main()
