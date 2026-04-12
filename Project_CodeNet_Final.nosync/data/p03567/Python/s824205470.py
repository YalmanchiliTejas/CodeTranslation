S = input()

x = 'No'
if S == 'AC':
    x = 'Yes'
    
for i in range(len(S)-2):
    s = S[i:i+2]
    if s == 'AC':
        x = 'Yes'
        break

print(x)
