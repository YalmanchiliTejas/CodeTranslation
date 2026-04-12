a = input()
b = list(a)
hantei = "Yes"
if b[0] == b[1] and b[1] == b[2] and b[2] == b[0]:
  hantei = "No"
print(hantei)