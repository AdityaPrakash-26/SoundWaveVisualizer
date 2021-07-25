# Sound Wave Visualizer
An Unreal Engine 4 utility tool, allowing you to visualize sound waves in 3D. Easy to integrate and minimum dependencies.

![Gif](1600348737376.gif)

## Features
- Use any of the default 3D props or even upload your own.
- Customiseable sound range, to achieve the visualization you want.
- Edit the sound track.
- Change number of bars/meshes.

## How it works?
The most important part of the code is:
```cpp
for(auto SpecData : TimeSynthComponent->GetSpectralData()){
    UStaticMeshComponent* SpectrumBar = SpectrumBars[SpecData.FrequencyHz / 50.f  -  1];
        
    FVector BarScale = SpectrumBar->GetComponentScale();
    BarScale.Z = 1.f + SpecData.Magnitude/5.f;
    SpectrumBar->SetWorldScale3D(FMath::VInterpTo(SpectrumBar->GetComponentScale(), BarScale, DeltaTime, 5.f));
}
```
The `TimeSynthComponent` returns the spectral data(which has several properties like frequencies, magnitude etc). Firstly, we pull the Frequency(in Hz) from the data, and divide it by `50` to get the bar we wish to modify. That is, every bar in the array/mesh spans over a range of `50 Hz`. (Note: the `-1` is there for the index).

Next, we change the Z-length, or the height of the bar calculated above. This is divided by `5` (or we can choose any other number), to get the new scale. Finally, we intepolate from current height to the calculated height.

## Setup
- Install Epic games from their [website](https://www.epicgames.com/store/en-US/)
- Navigate to Unreal Engine in the sidebar
- Download Unreal Engine 4.25.3
- Open the project
