n=int(input())
can=n*800
p=n
des=200
if n<15:
  total=can
elif n>=15 and n<30:
  total=can-200
elif n>=30 and n<45:
  total=can-400
elif n>=45 and n<60:
  total=can-600
elif n>=60 and n<75:
  total=can-800
elif n>=75 and n<90:
  total=can-1000
elif n>=90 and n<=100:
  total=can-1200
print(total)
  