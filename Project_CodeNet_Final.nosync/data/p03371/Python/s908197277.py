def main():
  A, B, C, X, Y = map(int, input().split())
  print(min([C*max(X, Y)*2, A*X + B*Y, 2*C*Y+A*(max(0, X-Y)), 2*C*X + B*(max(0, Y-X))]))
if __name__ == "__main__":
  main()