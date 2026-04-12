import sys
N,M=map(int, input().split())

if N<=100 and N>=1:
  if M==N:
    print("Yes")
    sys.exit()
print("No")
sys.exit()