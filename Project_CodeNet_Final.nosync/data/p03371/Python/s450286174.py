a,b,c,x,y = map(int, input().split())

mins, maxs = min(x,y), max(x,y)
diff = maxs - mins

total = min((a+b) * mins, c * mins*2)

pp = a if x > y else b
total += (pp if pp < c * 2 else c * 2 ) * diff
print(total)