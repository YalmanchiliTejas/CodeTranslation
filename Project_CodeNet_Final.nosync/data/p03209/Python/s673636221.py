import collections
n,x = map(int, raw_input().split(' '))
x-=1
mem = {}
def compute(n):
	if n in mem:
		return mem[n]
	if n == 0:
		return (1,1)
	else:
		h,p = compute(n-1)
		return (2*h + 3, 2*p + 1) 	
def iot(n,x,r,h):
	if h[0] > x: return
	if n == 0:
		h[0] += 1
		r[0] += 1
		return
	h[0] += 1
	if h[0] > x: return
	
	if h[0] + compute(n-1)[0] <= x:
		hh,pp = compute(n-1)
		h[0] += hh
		r[0] += pp
	else:
		iot(n-1, x, r, h)
	if h[0] > x: return
	
	h[0] += 1
	r[0] += 1

	if h[0] > x: return
	
	if h[0] + compute(n-1)[0] <= x:
		hh,pp = compute(n-1)
		h[0] += hh
		r[0] += pp
	else:
		iot(n-1, x, r, h)
	
	
	if h[0] > x: return
	
	h[0] +=1		
r,h = [0],[0]
iot(n,x,r,h)
print r[0]