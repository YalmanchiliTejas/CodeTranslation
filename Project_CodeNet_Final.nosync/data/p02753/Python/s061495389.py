S = list(input())
for i in range(len(S)):
  if (i == (len(S) - 1)):
    break
  if ( 'A' in (S[i] + S[i + 1]) and 'B' in (S[i] + S[i + 1]) ):
    print("Yes")
    exit()
print("No")
