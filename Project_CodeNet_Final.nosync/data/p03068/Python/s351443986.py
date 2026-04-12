import sys
def p(*a):
  s=" ".join(map(str,a))
  #print(s)
  sys.stderr.write(s+"\n")


N=int(input())
S=input()
K=int(input())

c=S[K-1]

ans=""
# 1文字ずつ処理
s = "abcdefghijklmnopqrstuvwxyz"
for a in S:
	if a==c:
		ans = ans + a
	else:
		ans = ans + '*'

print(ans)

