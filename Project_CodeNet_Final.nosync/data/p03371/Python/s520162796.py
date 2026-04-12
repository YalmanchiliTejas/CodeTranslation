iA,iB,iC,iX,iY = map(int,input().split())


if iY > iX:
    iX,iY = iY,iX
    iA,iB = iB,iA
print(min(2*iC*iX ,iX*iA+iY*iB, (iA+iB)*iY+2*iC*(iX-iY),2*iC*iY+iA*(iX-iY)))
