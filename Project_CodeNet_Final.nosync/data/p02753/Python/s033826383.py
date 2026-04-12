from sys import stdin
s = str(stdin.readline().rstrip())
#l = list(map(int, stdin.readline().rstrip().split()))
#A, B, C = map(int, stdin.readline().rstrip().split())
#S = [list(map(int, stdin.readline().rstrip().split())) for _ in range(h)]#hの定義を忘れずに
if s[0]==s[1]==s[2]:
    print("No")
else:
    print("Yes")
