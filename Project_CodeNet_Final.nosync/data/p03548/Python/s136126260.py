
x,y,z = map(int, raw_input().split())
cumul = x / (y + z)
x %= y + z
if x < z:
	cumul -=1
print max(cumul,0)