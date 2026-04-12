def I_N():
	return int(input())

def I_N_S():
	return map(int, input().split())

N = I_N()
print(N*800 - (N//15)*200)
