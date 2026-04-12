import collections
N = int(input())
mojiNum = list()
for n in range(26):
  mojiNum.append(50);
  
for n in range(N):
  temp = input()
  mojikind = collections.Counter(temp)
  for i in range(26):
    mojiNum[i] = min(mojiNum[i], mojikind[chr(i + 97)])
ans = ""
for n in range(26):
  for i in range(mojiNum[n]):
    ans += chr(97 + n)
if ans == "":
  print(" ")
else:
  print(ans)