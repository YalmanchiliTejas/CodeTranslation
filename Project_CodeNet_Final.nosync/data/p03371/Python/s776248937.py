def main():
  A,B,C,X,Y = list(map(int, input().split()))

  min_cost = 2 * (10 ** 5) * max(A, B, C)

  for i in range(max(X, Y) + 1):
    num_c = 2 * (max(X, Y) - i)
    num_b = max(0, Y - num_c // 2)
    num_a = max(0, X - num_c // 2)
    total = A * num_a + B * num_b + C * num_c
    min_cost = min(total, min_cost)

  print(min_cost)

if __name__ == "__main__":
    main()