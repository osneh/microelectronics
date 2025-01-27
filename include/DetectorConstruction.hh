//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// -------------------------------------------------------------------
// -------------------------------------------------------------------
//  History :
//    21/10/2021 DLa  update to manage the change of material
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Sphere.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4UserLimits.hh"
#include "G4VisAttributes.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class G4Region;
class DetectorMessenger;

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:

  DetectorConstruction();

  ~DetectorConstruction();

  G4VPhysicalVolume* Construct();

  void SetSize     (G4double);              
  void SetMaterial (const G4String&);

  inline const G4VPhysicalVolume* GetWorld() const {return fPhysiWorld;};
  inline G4double GetSize() const                  {return fBoxSize;};      
  inline const G4Material* GetMaterial() const     {return fMaterial;};

  G4double GetWorldSizeZ() const                {return fWorldSizeZ;}; // Added by Henso

  void   PrintParameters();
  void   DefineMaterials(); 

  G4Region* GetTargetRegion()  {return fRegion;}
  //G4Region* GetWorldRegion()  {return fWorld;}
                         
private:
   
  G4double           fWorldSizeX;
  G4double           fWorldSizeY;
  G4double           fWorldSizeZ;

  G4VPhysicalVolume* fPhysiWorld;
  G4LogicalVolume*   fLogicWorld;  
  G4Box*             fSolidWorld;

  G4Material*        fWorldMaterial;
  G4LogicalVolume*   flogicTarget;
  G4Box*             ftargetSolid;
 
  G4double           fXposTarget;
  G4double           fXstartTarget, fXendTarget;

  G4double           fBoxSize;  
  G4Material*        fMaterial; 
  G4Region*          fRegion;
  //G4Region*          fWorld;

  DetectorMessenger* fDetectorMessenger;

  G4VPhysicalVolume* ConstructDetector();     
};
#endif
