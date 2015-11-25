// Generated by Apple Swift version 2.1.1 (swiftlang-700.1.101.13 clang-700.1.81)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Foundation;
@import Dispatch;
@import GameController;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"

/// appRole: The appRole value must ONLY be set by passing it as a parameter to startAs.
///
/// \param .Central The consumer of the Peripheral data, typically a game.
///
/// \param .Peripheral A game controller that may be a hardware controller or a
/// VGC software controller, it receives input from a user through
/// Elements (buttons, thumbsticks, accelerometer, etc.) and sends
/// those values to either a Bridge or a Central.
///
/// \param .Bridge An intermediary between Peripherals and the Central, which
/// effectively functions as both a Central and Peripheral, usually
/// forwarding element values to the Central, although it may also
/// process those values in terms of calling handlers. An iPhone
/// positioned in a slide-on controller will typically function as
/// as a Bridge (although it can also be a Central).  An iPhone paired
/// with an Apple Watch that is functioning as a Peripheral will act
/// as a Bridge.
///
/// \param .EnhancementBridge Special Bridge mode for using a form-fitting/slide-on controller
/// with an iPhone.  Prevents additional Peripherals from connecting.
typedef SWIFT_ENUM(NSInteger, AppRole) {
  AppRoleCentral = 0,
  AppRolePeripheral = 1,
  AppRoleBridge = 2,
  AppRoleEnhancementBridge = 3,
};


/// ControllerType enumeration: Most values are for informational purposes, except MFiHardware, which is used to trigger the "wrapped" approach to handling hardware controllers in VgcController.
typedef SWIFT_ENUM(NSInteger, ControllerType) {
  ControllerTypeSoftware = 0,
  ControllerTypeMFiHardware = 1,
  ControllerTypeICadeHardware = 2,
  ControllerTypeBridgedMFiHardware = 3,
  ControllerTypeBridgedICadeHardware = 4,
  ControllerTypeWatch = 5,
};

enum ElementType : NSInteger;
@class VgcController;
@class NSCoder;


/// Element is a class that represents each element/control on a controller, such as Button A or dpad. Along with describing the controller element in terms of name and data type,and providing a unique identifier used when transmitting values, an element functions as the backing store that allows for multiple profiles to share the same underlying data set.  For example, because the Gamepad profile is a subset of the Extended Gamepad, the element provides the basis for providing access to values through both profile interfaces for the same controller.
///
/// \param type ElementType enumerates the standard set of controller elements, plus a few system-
/// related elements, DeviceInfoElement, SystemMessage and Custom.
///
/// \param dataType Currently three data types are supported, .String, .Int, and .Float, enumerated
/// in ElementDataType.
///
/// \param name Human-readable name for the element.
///
/// \param value The canonical value for the element.
///
/// \param getterKeypath Path to the VgcController class interface for getting the value of the element.
///
/// \param setterKeypath Path to the VgcController class interface for triggering the developer-defined
/// handlers for the element.
///
/// \param identifier A unique integer indentifier used to identify the element a value belongs to
/// when transmitting the value over the network.
///
/// \param mappingComplete A state management value used as a part of the peripheral-side element mapping system.
SWIFT_CLASS("_TtC21VirtualGameController7Element")
@interface Element : NSObject
@property (nonatomic) enum ElementType type;
@property (nonatomic, copy) NSString * __nonnull name;
@property (nonatomic, strong) id __nonnull value;
@property (nonatomic, copy) NSString * __nonnull getterKeypath;
@property (nonatomic, copy) NSString * __nonnull setterKeypath;
@property (nonatomic, copy) void (^ __null_unspecified valueChangedHandler)(VgcController * __nonnull, Element * __nonnull);
@property (nonatomic, copy) void (^ __null_unspecified valueChangedHandlerForPeripheral)(Element * __nonnull);
@property (nonatomic, readonly) NSInteger hashValue;
- (NSString * __nonnull)getterKeypath:(VgcController * __nonnull)controller;
- (NSString * __nonnull)setterKeypath:(VgcController * __nonnull)controller;
- (nonnull instancetype)initWithCoder:(NSCoder * __nonnull)decoder;
- (void)encodeWithCoder:(NSCoder * __nonnull)coder;
@property (nonatomic, copy) NSString * __nonnull valueAsBase64String;
@end


SWIFT_CLASS("_TtC21VirtualGameController13CustomElement")
@interface CustomElement : Element
- (nonnull instancetype)initWithCoder:(NSCoder * __nonnull)decoder;
@end


SWIFT_CLASS("_TtC21VirtualGameController24CustomElementsSuperclass")
@interface CustomElementsSuperclass : NSObject
@property (nonatomic, copy) void (^ __null_unspecified valueChangedHandler)(VgcController * __nonnull, Element * __nonnull);
@property (nonatomic, copy) NSArray<Element *> * __nonnull customProfileElements;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC21VirtualGameController24CustomMappingsSuperclass")
@interface CustomMappingsSuperclass : NSObject
@property (nonatomic, copy) NSDictionary<NSNumber *, NSNumber *> * __nonnull mappings;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

enum ProfileType : NSInteger;


/// DeviceInfo contains key properties of a controller, either hardware or software.
///
/// \param deviceUID Unique identifier for the controller.  Hardware controllers have this built-in.  An arbitrary identifier can be given to a software controller, and the NSUUID().UUIDString function is recommended.
///
/// \param vendorName Built-in to a hardware controller.  For software controllers, either define a name or use an empty string "" and the machine/device name will be used.
///
/// \param profileType Built-in to a hardware controller.  This can be aribtrarily set to either extendedGamepad or Gamepad for a software controller, and will determine what elements are available to the controller.  microGamepad is only available in the tvOS context and is untested with software controllers.
///
/// \param supportsMotion Built-in parameter with a hardware controller (the Apple TV remote is the only hardware controller known to support motion). This can be set when defining a software controller, but would be overriden on the basis of the availabiity of Core Motion.  For example, an OSX-based software controller would report supports motion as false.
SWIFT_CLASS("_TtC21VirtualGameController10DeviceInfo")
@interface DeviceInfo : NSObject <NSCoding>
@property (nonatomic, readonly, copy) NSString * __nonnull vendorName;
@property (nonatomic, readonly) BOOL attachedToDevice;
@property (nonatomic, readonly) enum ProfileType profileType;
@property (nonatomic, readonly) enum ControllerType controllerType;
@property (nonatomic, readonly) BOOL supportsMotion;
- (nonnull instancetype)initWithDeviceUID:(NSString * __nonnull)deviceUID vendorName:(NSString * __nonnull)vendorName attachedToDevice:(BOOL)attachedToDevice profileType:(enum ProfileType)profileType controllerType:(enum ControllerType)controllerType supportsMotion:(BOOL)supportsMotion OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, copy) NSString * __nonnull description;
- (nonnull instancetype)initWithCoder:(NSCoder * __nonnull)decoder;
- (void)encodeWithCoder:(NSCoder * __nonnull)coder;
@end


typedef SWIFT_ENUM(NSInteger, ElementType) {
  ElementTypeDeviceInfoElement = 0,
  ElementTypeSystemMessage = 1,
  ElementTypePlayerIndex = 2,
  ElementTypePauseButton = 3,
  ElementTypeLeftShoulder = 4,
  ElementTypeRightShoulder = 5,
  ElementTypeDpadXAxis = 6,
  ElementTypeDpadYAxis = 7,
  ElementTypeButtonA = 8,
  ElementTypeButtonB = 9,
  ElementTypeButtonX = 10,
  ElementTypeButtonY = 11,
  ElementTypeLeftThumbstickXAxis = 12,
  ElementTypeLeftThumbstickYAxis = 13,
  ElementTypeRightThumbstickXAxis = 14,
  ElementTypeRightThumbstickYAxis = 15,
  ElementTypeLeftTrigger = 16,
  ElementTypeRightTrigger = 17,
  ElementTypeMotionUserAccelerationX = 18,
  ElementTypeMotionUserAccelerationY = 19,
  ElementTypeMotionUserAccelerationZ = 20,
  ElementTypeMotionAttitudeX = 21,
  ElementTypeMotionAttitudeY = 22,
  ElementTypeMotionAttitudeZ = 23,
  ElementTypeMotionAttitudeW = 24,
  ElementTypeMotionRotationRateX = 25,
  ElementTypeMotionRotationRateY = 26,
  ElementTypeMotionRotationRateZ = 27,
  ElementTypeMotionGravityX = 28,
  ElementTypeMotionGravityY = 29,
  ElementTypeMotionGravityZ = 30,
  ElementTypeCustom = 31,
};



/// The Elements class describes the full population of controller controls, as well as providing definitions of the population of elements for each profile type.
SWIFT_CLASS("_TtC21VirtualGameController8Elements")
@interface Elements : NSObject
@property (nonatomic, copy) NSArray<Element *> * __nonnull watchProfileElements;
+ (CustomElementsSuperclass * __null_unspecified)customElements;
+ (void)setCustomElements:(CustomElementsSuperclass * __null_unspecified)value;
+ (CustomMappingsSuperclass * __null_unspecified)customMappings;
+ (void)setCustomMappings:(CustomMappingsSuperclass * __null_unspecified)value;
@property (nonatomic, copy) NSDictionary<NSNumber *, Element *> * __nonnull custom;
@property (nonatomic, copy) NSArray<Element *> * __nonnull customProfileElements;
- (NSArray<Element *> * __nonnull)allElementsCollection;
- (NSArray<Element *> * __nonnull)elementsForController:(VgcController * __nonnull)controller;
@property (nonatomic, strong) Element * __nonnull systemMessage;
@property (nonatomic, strong) Element * __nonnull deviceInfoElement;
@property (nonatomic, strong) Element * __nonnull playerIndex;
@property (nonatomic, strong) Element * __nonnull pauseButton;
@property (nonatomic, strong) Element * __nonnull leftShoulder;
@property (nonatomic, strong) Element * __nonnull rightShoulder;
@property (nonatomic, strong) Element * __nonnull dpadXAxis;
@property (nonatomic, strong) Element * __nonnull dpadYAxis;
@property (nonatomic, strong) Element * __nonnull buttonA;
@property (nonatomic, strong) Element * __nonnull buttonB;
@property (nonatomic, strong) Element * __nonnull buttonX;
@property (nonatomic, strong) Element * __nonnull buttonY;
@property (nonatomic, strong) Element * __nonnull leftThumbstickXAxis;
@property (nonatomic, strong) Element * __nonnull leftThumbstickYAxis;
@property (nonatomic, strong) Element * __nonnull rightThumbstickXAxis;
@property (nonatomic, strong) Element * __nonnull rightThumbstickYAxis;
@property (nonatomic, strong) Element * __nonnull rightTrigger;
@property (nonatomic, strong) Element * __nonnull leftTrigger;
@property (nonatomic, strong) Element * __nonnull motionUserAccelerationX;
@property (nonatomic, strong) Element * __nonnull motionUserAccelerationY;
@property (nonatomic, strong) Element * __nonnull motionUserAccelerationZ;
@property (nonatomic, strong) Element * __nonnull motionRotationRateX;
@property (nonatomic, strong) Element * __nonnull motionRotationRateY;
@property (nonatomic, strong) Element * __nonnull motionRotationRateZ;
@property (nonatomic, strong) Element * __nonnull motionGravityX;
@property (nonatomic, strong) Element * __nonnull motionGravityY;
@property (nonatomic, strong) Element * __nonnull motionGravityZ;
@property (nonatomic, strong) Element * __nonnull motionAttitudeX;
@property (nonatomic, strong) Element * __nonnull motionAttitudeY;
@property (nonatomic, strong) Element * __nonnull motionAttitudeZ;
@property (nonatomic, strong) Element * __nonnull motionAttitudeW;
- (Element * __null_unspecified)elementFromType:(enum ElementType)type;
- (Element * __null_unspecified)elementFromIdentifier:(NSInteger)identifier;
@end

@class VgcService;

SWIFT_CLASS("_TtC21VirtualGameController10Peripheral")
@interface Peripheral : NSObject

/// Key method used to send a change in an element's state to the Central or Bridge that we're currently connected to with this Peripheral.  "State" in this case refers to the Element "value" property.
- (void)sendElementState:(Element * __nonnull)element;

/// DeviceInfo for the controller represented by this Peripheral instance.
@property (nonatomic, strong) DeviceInfo * __null_unspecified deviceInfo;

/// Connect to a Central or Bridge using a VgcService object obtained by browsing the network.
- (void)connectToService:(VgcService * __nonnull)vgcService;
- (void)disconnectFromService;
- (void)browseForServices;
- (void)stopBrowsingForServices;
@property (nonatomic, readonly, copy) NSArray<VgcService *> * __nonnull availableServices;
@end

typedef SWIFT_ENUM(NSInteger, ProfileType) {
  ProfileTypeUnknown = 0,
  ProfileTypeMicroGamepad = 1,
  ProfileTypeGamepad = 2,
  ProfileTypeExtendedGamepad = 3,
  ProfileTypeMotion = 4,
  ProfileTypeWatch = 5,
};

@class VgcMotion;
@class VgcMicroGamepad;
@class VgcExtendedGamepad;
@class VgcGamepad;


/// VgcController is a wrapper around GCController.  Each instance represents a hardware or software controller.  Hardware controllers use GCController, and are wrapped by VgcController, but handlers and properties are simply passed through to provide optimal performance. The VgcController class provides muchly the same interface as GCController, but does not descend from it.  In the case of a hardware controller connected to the system, VgcController encapsulates the controller in the var hardwareController, and maps it's properties to it's own.  This provides a single interface to both custom/software controllers and hardware controllers.
SWIFT_CLASS("_TtC21VirtualGameController13VgcController")
@interface VgcController : NSObject <NSNetServiceDelegate, NSStreamDelegate>
@property (nonatomic, weak) Peripheral * __null_unspecified peripheral;
@property (nonatomic, strong) Elements * __null_unspecified elements;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
+ (VgcController * __null_unspecified)iCadeController;
+ (void)setICadeController:(VgcController * __null_unspecified)value;

/// On the Central (or Bridge) side only a single iCade controller at one time is allowed because of the way iCade controllers represent themselves as keyboards and the need to direct input to a text entry field.  A text entry field (hidden) must be added to your game to support Central-side iCade controller functionality. Peripheral-side iCade controllers are also supported and allow for multiple controllers, but require the use of an iOS device (in Peripheral mode)
+ (void)enableIcadeController;
+ (NSArray<VgcController *> * __nonnull)controllers;
+ (void)startWirelessControllerDiscoveryWithCompletionHandler:(void (^ __nullable)(void))_completionHandler;
+ (void)stopWirelessControllerDiscovery;
+ (void)sendElementStateToAllPeripherals:(Element * __nonnull)element;
- (void)sendElementStateToPeripheral:(Element * __nonnull)element;
- (void)disconnect;
- (void)triggerElementHandlers:(Element * __nonnull)element value:(float)value;
@property (nonatomic, strong) dispatch_queue_t __nonnull handlerQueue;
@property (nonatomic, copy) void (^ __nullable controllerPausedHandler)(VgcController * __nonnull);
@property (nonatomic, readonly, strong) VgcMotion * __nullable motion;
@property (nonatomic, strong) DeviceInfo * __null_unspecified deviceInfo;

/// Convienance function for profile type
@property (nonatomic, readonly) enum ProfileType profileType;

/// Some controllers directly attach to the game-playing iOS device, such as a slide-on controller.
@property (nonatomic, readonly) BOOL attachedToDevice;
@property (nonatomic, readonly, copy) NSString * __nonnull vendorName;
@property (nonatomic) GCControllerPlayerIndex playerIndex;
@property (nonatomic, readonly, strong) VgcMicroGamepad * __nullable microGamepad;
@property (nonatomic, readonly, strong) VgcExtendedGamepad * __nullable extendedGamepad;
@property (nonatomic, readonly, strong) VgcGamepad * __nullable gamepad;
@end

@class GCController;
@class GCControllerButtonInput;
@class GCControllerDirectionPad;
@class VgcExtendedGamepadSnapshot;

SWIFT_CLASS("_TtC21VirtualGameController18VgcExtendedGamepad")
@interface VgcExtendedGamepad : GCExtendedGamepad

/// Reference to the VgcController that owns this profile.
@property (nonatomic, strong) VgcController * __null_unspecified vgcController;
- (nonnull instancetype)initWithCoder:(NSCoder * __nonnull)decoder;

/// Returns a GCController hardware controller, if one is available. vgcController must be used to get a reference to the VgcController, which represents software controllers (as well as being a wrapper around the hardware controller.
@property (nonatomic, readonly, weak) GCController * __nullable controller;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull leftShoulder;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull rightShoulder;
@property (nonatomic, readonly, strong) GCControllerDirectionPad * __nonnull dpad;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonA;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonB;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonX;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonY;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull leftTrigger;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull rightTrigger;
@property (nonatomic, readonly, strong) GCControllerDirectionPad * __nonnull leftThumbstick;
@property (nonatomic, readonly, strong) GCControllerDirectionPad * __nonnull rightThumbstick;
@property (nonatomic, copy) GCExtendedGamepadValueChangedHandler __nullable valueChangedHandler;
- (VgcExtendedGamepadSnapshot * __nonnull)vgcSaveSnapshot;
@end

@class NSData;

SWIFT_CLASS("_TtC21VirtualGameController26VgcExtendedGamepadSnapshot")
@interface VgcExtendedGamepadSnapshot : NSObject
- (nonnull instancetype)initWithController:(VgcController * __nonnull)controller OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithController:(VgcController * __nonnull)controller snapshotData:(NSData * __nonnull)snapshotData OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithSnapshotData:(NSData * __nonnull)snapshotData OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, strong) GCControllerDirectionPad * __nonnull dpad;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonA;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonB;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonX;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonY;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull leftShoulder;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull rightShoulder;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull leftTrigger;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull rightTrigger;
@property (nonatomic, readonly, strong) GCControllerDirectionPad * __nonnull rightThumbstick;
@property (nonatomic, readonly, strong) GCControllerDirectionPad * __nonnull leftThumbstick;
@property (nonatomic, strong) NSData * __nonnull snapshotData;
@end

@class VgcGamepadSnapshot;

SWIFT_CLASS("_TtC21VirtualGameController10VgcGamepad")
@interface VgcGamepad : GCGamepad

/// Reference to the VgcController that owns this profile.
@property (nonatomic, strong) VgcController * __nullable vgcController;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull leftShoulder;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull rightShoulder;
@property (nonatomic, readonly, strong) GCControllerDirectionPad * __nonnull dpad;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonA;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonB;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonX;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonY;

/// Returns a GCController hardware controller, if one is available. vgcController must be used to get a reference to the VgcController, which represents software controllers (as well as being a wrapper around the hardware controller.
@property (nonatomic, readonly, weak) GCController * __nullable controller;

/// Same behavior as the GCController version.
@property (nonatomic, copy) GCGamepadValueChangedHandler __nullable valueChangedHandler;
- (VgcGamepadSnapshot * __nonnull)vgcSaveSnapshot;
@end


SWIFT_CLASS("_TtC21VirtualGameController18VgcGamepadSnapshot")
@interface VgcGamepadSnapshot : NSObject
- (nonnull instancetype)initWithController:(VgcController * __nonnull)controller OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithController:(VgcController * __nonnull)controller snapshotData:(NSData * __nonnull)snapshotData OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithSnapshotData:(NSData * __nonnull)snapshotData OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, strong) GCControllerDirectionPad * __nonnull dpad;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonA;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonB;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonX;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonY;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull leftShoulder;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull rightShoulder;
@property (nonatomic, strong) NSData * __nonnull snapshotData;
@end


SWIFT_CLASS("_TtC21VirtualGameController18VgcIcadePeripheral")
@interface VgcIcadePeripheral : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC21VirtualGameController10VgcManager")
@interface VgcManager : NSObject
+ (enum AppRole)appRole;
+ (void)setAppRole:(enum AppRole)value;

/// Shared set of elements (in contrast to controllers on a Central/Bridge, each of which have their own set of elements).
+ (Elements * __nonnull)elements;
+ (void)setElements:(Elements * __nonnull)value;

/// Used as a component of the bonjour names for the various app types. This should be set to something that uniquely identifies your app.
+ (NSString * __nonnull)appIdentifier;
+ (void)setAppIdentifier:(NSString * __nonnull)value;

/// An app in Bridge mode can call it's handlers or simply relay data forward to the Central.  Relaying is more performant.
+ (BOOL)bridgeRelayOnly;
+ (void)setBridgeRelayOnly:(BOOL)value;
+ (VgcIcadePeripheral * __null_unspecified)iCadePeripheral;
+ (void)setICadePeripheral:(VgcIcadePeripheral * __null_unspecified)value;

/// We support mapping from either the Peripheral or Central side.  Central-side mapping is recommended; it is more efficient because two values do not need to be transmitted. Central-side mapping also works with hardware controllers.
+ (BOOL)usePeripheralSideMapping;
+ (void)setUsePeripheralSideMapping:(BOOL)value;
+ (NSInteger)netServiceBufferSize;
+ (void)setNetServiceBufferSize:(NSInteger)value;
+ (BOOL)includesPeerToPeer;
+ (void)setIncludesPeerToPeer:(BOOL)value;

/// Controls how long we wait before averaging the number of messages transmitted/received per second when logging performance.  Set to 0 to disable.
+ (float)performanceSamplingDisplayFrequency;
+ (void)setPerformanceSamplingDisplayFrequency:(float)value;
+ (Peripheral * __null_unspecified)peripheral;
+ (void)setPeripheral:(Peripheral * __null_unspecified)value;
+ (NSString * __nonnull)centralServiceName;
+ (void)setCentralServiceName:(NSString * __nonnull)value;

/// Simplified version of startAs when custom mapping and custom elements are not needed
+ (void)startAs:(enum AppRole)appRole appIdentifier:(NSString * __nonnull)appIdentifier;

/// Kicks off the search for software controllers.  This is a required method and should be called early in the application launch process.
+ (void)startAs:(enum AppRole)appRole appIdentifier:(NSString * __nonnull)appIdentifier customElements:(CustomElementsSuperclass * __null_unspecified)customElements customMappings:(CustomMappingsSuperclass * __null_unspecified)customMappings;
@end

@class VgcMicroGamepadSnapshot;

SWIFT_CLASS("_TtC21VirtualGameController15VgcMicroGamepad")
@interface VgcMicroGamepad : GCMicroGamepad
@property (nonatomic, strong) VgcController * __nullable vgcController;

/// Returns a GCController hardware controller, if one is available. vgcController must be used to get a reference to the VgcController, which represents software controllers (as well as being a wrapper around the hardware controller.
@property (nonatomic, readonly, weak) GCController * __nullable controller;
@property (nonatomic) BOOL reportsAbsoluteDpadValues;
@property (nonatomic) BOOL allowsRotation;
@property (nonatomic, readonly, strong) GCControllerDirectionPad * __nonnull dpad;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonA;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonX;
@property (nonatomic, copy) GCMicroGamepadValueChangedHandler __nullable valueChangedHandler;
- (VgcMicroGamepadSnapshot * __nonnull)vgcSaveSnapshot;
@end


SWIFT_CLASS("_TtC21VirtualGameController23VgcMicroGamepadSnapshot")
@interface VgcMicroGamepadSnapshot : NSObject
- (nonnull instancetype)initWithController:(VgcController * __nonnull)controller OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithController:(VgcController * __nonnull)controller snapshotData:(NSData * __nonnull)snapshotData OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithSnapshotData:(NSData * __nonnull)snapshotData OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, strong) GCControllerDirectionPad * __nonnull dpad;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonA;
@property (nonatomic, readonly, strong) GCControllerButtonInput * __nonnull buttonX;
@property (nonatomic, strong) NSData * __nonnull snapshotData;
@end


SWIFT_CLASS("_TtC21VirtualGameController9VgcMotion")
@interface VgcMotion : NSObject

/// Returns a GCController hardware controller, if one is available. vgcController must be used to get a reference to the VgcController, which represents software controllers (as well as being a wrapper around the hardware controller.
@property (nonatomic, readonly, weak) GCController * __nullable controller;
@property (nonatomic) GCAcceleration userAcceleration;
@property (nonatomic) GCQuaternion attitude;
@property (nonatomic) GCRotationRate rotationRate;
@property (nonatomic) GCAcceleration gravity;
@property (nonatomic, copy) void (^ __nullable valueChangedHandler)(VgcMotion * __nonnull);
@end


SWIFT_CLASS("_TtC21VirtualGameController10VgcService")
@interface VgcService : NSObject
@property (nonatomic, copy) NSString * __nonnull name;
@property (nonatomic) enum AppRole type;
@property (nonatomic, readonly, copy) NSString * __nonnull fullName;
@end

#pragma clang diagnostic pop
