import pbPlots
import supportLib

h = 0.01
m = 1
k = 20

x = [1]
v = [0]
a = [-20]
t = [0]

n = int(input("How long do you want it to be?"))

for i in range(1, n):
  x.append(0)
  t.append(0)
  v.append(0)
  a.append(0)

for i in range(1, n):
  t[i] = t[i-1] + h
  x[i] = x[i-1] + v[i-1] * h
  v[i] = v[i-1] + a[i-1] * h
  a[i] = -k * x[i]

imageReference = pbPlots.CreateRGBABitmapImageReference()
pbPlots.DrawScatterPlot(imageReference, 800, 600, t, x)

pngdata = pbPlots.ConvertToPNG(imageReference.image)
supportLib.WriteToFile(pngdata, "SprPlot.png")
pbPlots.DeleteImage(imageReference.image)