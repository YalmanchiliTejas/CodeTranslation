a,b,c,x,y=[int(i) for i in input().split()]

#双対問題の最大化

gyou=4 #目的関数＋スラック変数λ1～λ3
retsu=6 #x, y＋スラック変数λ1～λ3＋定数項

matrix=[[0 for i in range(retsu)] for j in range(gyou)]

#評価関数
matrix[0][0], matrix[0][1]= -x, -y 
#ピッツァ
matrix[1][0], matrix[1][1]= 1, 0
matrix[2][0], matrix[2][1]= 0, 1
matrix[3][0], matrix[3][1]= 1, 1
#定数項
matrix[1][5], matrix[2][5], matrix[3][5]=a, b, 2*c

#スラック変数
matrix[1][2]=1
matrix[2][3]=1
matrix[3][4]=1

for i in range(10):
    if min(matrix[0])>=0:
        break
    else:
        p_column=min(enumerate(matrix[0]), key=lambda x: x[1])[0]
        const_per_p=[10**6 for i in range(gyou)]

    for j in range(gyou):
        if matrix[j][p_column]>0:
            const_per_p[j]=matrix[j][5]/matrix[j][p_column]

            k_row=min(enumerate(const_per_p), key=lambda x: x[1])[0]
            pivot=matrix[k_row][p_column]

            new_matrix=[[0 for i in range(retsu)] for j in range(gyou)]
            for l in range(gyou):
                for j in range(retsu):
                    if l==k_row:
                       new_matrix[l][j]/=pivot
                    else:
                       new_matrix[l][j]=matrix[l][j]-matrix[l][p_column]*matrix[k_row][j]/pivot

    matrix=new_matrix[:][:]

print(int(matrix[0][5]))



