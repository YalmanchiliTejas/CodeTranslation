while 1:
    try:
        s=input()
        s_c=""
        c1=[" ",".",",","-","'","?"]
        for i in s:
            if 64<ord(i)<91:
                s_c+=str(bin(ord(i)-65)[2:]).zfill(5)
            else:
                s_c+=str(bin(c1.index(i)+26)[2:]).zfill(5)

        ch_3=["101","110","111"]
        re_3=[" ","E","P"]
        ch_4=["0101","0001","0111","0110","1000"]
        re_4=["C","D","I","K","R"]
        ch_5=["01001","00100","00101","00110","00111"]
        re_5=["F","L","O","S","T"]
        ch_6=["000000","000011","010001","000001","100101","010000","000010"]
        re_6=["'",",",".","?","A","H","W"]
        ch_8=["10010001","10011010","10011011","10011000","10011001","10011110","10011111","10011100","10011101","10010010","10010011","10010000"]
        re_8=["-","B","G","J","M","N","Q","U","V","X","Y","Z"]
        ans=""
        while 1:
            if len(s_c)==0 or len(s_c)<5 and int(s_c)==0:break
            elif s_c[:3] in ch_3:
                ans+=re_3[ch_3.index(s_c[:3])]
                s_c=s_c[3:]
            elif s_c[:4] in ch_4:
                ans+=re_4[ch_4.index(s_c[:4])]
                s_c=s_c[4:]
            elif s_c[:5] in ch_5:
                ans+=re_5[ch_5.index(s_c[:5])]
                s_c=s_c[5:]
            elif s_c[:6] in ch_6:
                ans+=re_6[ch_6.index(s_c[:6])]
                s_c=s_c[6:]
            elif s_c[:8] in ch_8:
                ans+=re_8[ch_8.index(s_c[:8])]
                s_c=s_c[8:]
            else:
                s_c+="0"
        print(ans)
    except:break
