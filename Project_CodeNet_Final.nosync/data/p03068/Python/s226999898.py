Length = int(input())
inputString = input()
SpecialIndex = int(input())
SpecialChar = inputString[SpecialIndex-1]
answer = ""
for i in inputString:
  if i != SpecialChar:
    answer += "*"
  else:
    answer += i
print(answer)
