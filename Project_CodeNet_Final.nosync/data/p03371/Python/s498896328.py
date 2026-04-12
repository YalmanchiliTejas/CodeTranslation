# 18:32 18:46
a, b, c, x, y = map(int, input().split())

#mxy = max(x, y)
#sxy = min(x, y)
#sum = 0
# if a+b-2*c > 0:
#    sum += c*min(x, y)*2
#    if x > y and a < 2*c:
#        sum += (max(x, y)-min(x, y))*a
#    elif x > y:
#        sum += (max(x, y)-min(x, y))*2*c
#    elif x <= y and a < 2*c:
#        sum += (max(x, y)-min(x, y))*b
#    elif x <= y:
#        sum += (max(x, y)-min(x, y))*2*c
# else:
#    sum = a*x+b*y
# print(sum)
#
amin = a*x+b*y
sum = 0
for i in range(0, max(x, y)*2+1, 2):
    sum = (x-i//2 if x-i//2 > 0 else 0)*a+(y-i//2 if y-i//2 > 0 else 0)*b+c*i
    if sum < amin:
        amin = sum
print(amin)