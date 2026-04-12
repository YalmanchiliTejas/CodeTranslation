S= int(input())
txt = list(input())
K= int(input())

key= txt[K-1]
for i in range(S):
  if txt[i] !=key:
    txt[i]="*"

print("".join(txt))