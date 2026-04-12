S = input()
flg=False
for i in range(len(S)-1):
    if S[i:i+2]=='AC':
        flg=True
        break
ans='Yes' if flg else 'No'
print(ans)