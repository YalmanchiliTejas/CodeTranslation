import sys
def input():
  return sys.stdin.readline().rstrip()

H,W=map(int,input().split())

count=0
for _ in range(H):
  count+=input().count("#")
print("Possible" if count==H+W-1 else "Impossible")
